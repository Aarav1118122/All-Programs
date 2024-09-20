import time
import pyautogui
# py.mouseInfo()
# time.sleep(10)
spam = 25

time.sleep(5)


# for i in range(100):
#     py.typewrite('o')
# py.typewrite('h')
# py.typewrite(["enter"])


#   TO SPAM A TEXT
for i in range(0, spam):
    pyautogui.typewrite("hi")
    time.sleep(0.5)
    pyautogui.typewrite(["enter"])


#   TO SPAM FROM A FILE
# spam = open("Spam.txt")
# for each_line in spam:
#     pyautogui.typewrite(each_line)
#     pyautogui.typewrite(["enter"])
