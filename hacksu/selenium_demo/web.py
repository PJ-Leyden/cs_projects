from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import selenium as sel
from webdriver_manager.chrome import ChromeDriverManager
import time

browser = sel.webdriver.Chrome(ChromeDriverManager().install())

browser.get("https://store.google.com/us/magazine/stadia?hl=en-US")

browser.maximize_window()
#browser.resize(1600, 900)

#browser.execute_script("alert('hacked google')")

body = browser.find_element_by_tag_name("body")

body.send_keys(Keys.UP)
body.send_keys(Keys.UP)

body.send_keys(Keys.DOWN)
body.send_keys(Keys.DOWN)

body.send_keys(Keys.LEFT)
body.send_keys(Keys.RIGHT)
body.send_keys(Keys.LEFT)
body.send_keys(Keys.RIGHT)

body.send_keys('b')
body.send_keys('a')

time.sleep(5)

browser.save_screenshot("konami_code.png")

time.sleep(2);

browser.close();