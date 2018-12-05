var gl;
//Vertex Manipulation
var points = [];
var start_verts = [];
var triangle_center = [];
var translation = [];
//Twist
var theta = 0;
var max_theta = Math.PI/2;
var untwist = false;

window.onload = function init(){
	//create canvas from canvas set up in html
	var canvas = document.getElementById("gl-canvas");
	//gl object given canvas
	gl = WebGLUtils.setupWebGL( canvas );
	//check
	if ( !gl ) { alert( "WebGL isn't available" );}

	//if we want to move the triangle around
	translation = [0, 0]; //negative works naturally
	triangle_center = [translation[0], translation[1]];

	//Setup initial vertecies
	//equallateral triangle 
	start_verts.push([-Math.sin(Math.PI/3) + translation[0], -Math.cos(Math.PI/3) + translation[1]]);
	start_verts.push([0                    + translation[0], 1                    + translation[1]]);
	start_verts.push([Math.sin(Math.PI/3)  + translation[0], -Math.cos(Math.PI/3) + translation[1]]);
	

	//Configure WebGL
	gl.viewport( 0, 0, canvas.width, canvas.height );
	gl.clearColor( 0.0, 0.0, 0.0, 1.0 );

	//Load shaders and initialize attribute buffers
	var program = initShaders( gl, "vertex-shader", "fragment-shader" );
	gl.useProgram(program);

	//Load the data into the GPU
	var bufferId = gl.createBuffer();
	gl.bindBuffer( gl.ARRAY_BUFFER, bufferId );
	gl.bufferData( gl.ARRAY_BUFFER, 8*Math.pow(4, 6), gl.STATIC_DRAW );

	//Associate our shader variables with our data buffer
	var vPosition = gl.getAttribLocation(program, "vPosition");
	gl.vertexAttribPointer( vPosition, 2, gl.FLOAT, false, 0, 0 );
	gl.enableVertexAttribArray( vPosition );

	setInterval(render, 100);
}

function rotate_point(p){
	var old_x = p[0];
	var old_y = p[1];
	var dist_center = Math.sqrt(Math.pow(triangle_center[0] - old_x, 2) + Math.pow(triangle_center[1] - old_y, 2));

	old_x -= translation[0];
	old_y -= translation[1];

	var x = old_x*Math.cos(theta * dist_center) - old_y*Math.sin(theta * dist_center);
	var y = old_y*Math.cos(theta * dist_center) + old_x*Math.sin(theta * dist_center); 
	
	return [(x + translation[0]), (y + translation[1])];
}

function sub_divide(a, b, c, num){
	if(num == 0){
		points.push(rotate_point(a));
		points.push(rotate_point(b));
		points.push(rotate_point(c));
		//points.push(a);
		//points.push(b);
		//points.push(c);
	}else{
		num--;
		var hpab = mix(a, b, .5);
		var hpac = mix(a, c, .5);
		var hpbc = mix(b, c, .5);

		sub_divide(hpab, hpac, a, num);
		sub_divide(hpab, hpbc, b, num);
		sub_divide(hpac, hpbc, c, num);

		sub_divide(hpab, hpac, hpbc, num);
	}
}

function render() { //called 10 times a second do to: setInterval(render, 100);
	points = [];
	
	if(untwist){
		theta = theta - .05;
		if(theta <= 0){
			untwist = false;
		}
	}else{
		theta = theta + .05;
		if(theta >= max_theta){
			untwist = true;
		}
	}

	sub_divide(start_verts[0], start_verts[1], start_verts[2], 5);

	gl.bufferSubData(gl.ARRAY_BUFFER, 0, flatten(points));
	gl.clear( gl.COLOR_BUFFER_BIT );
	gl.drawArrays(gl.TRIANGLES, 0, points.length);
}
