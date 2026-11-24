import time

while True:
    t = time.localtime()
    print('\r%02d:%02d:%02d' %(t.tm_hour, t.tm_min, t.tm_sec), end='')
        #\r: 將cursor移至最左邊再print
        #%02d: 保持2位數, 沒有就填0
        #end='': 取代平時print的newline, 也就是每次print都會取代上次那
        #        行，不會每次print都重新輸出一行
    time.sleep(1) #wait for 1s

#press ctrl+z to stop
