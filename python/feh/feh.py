import re,os
import time

def BackImager():
    filecwd = os.environ['HOME'] + '/.config/awesome/src/picom.conf'
    text = ''
    with open(filecwd,"r") as f:
        for line in f:
            if re.match('.*?\"class_g.*?\'st-256color\'\",',line):
                text += "#  \"class_g = 'st-256color'\",\n"
            else:
                text += line
    with open(filecwd,'w') as f:
        f.seek(0)
        f.truncate()
        f.write(text)

imager = os.environ['HOME'] + '/Imager/'



def CBackImager():
    pass



while True:
    ImagerList = os.listdir(imager)
    for f in ImagerList:
        if f == '1.jpg':
            BackImager()
        else:
            CBackImager()
        os.system('feh --randomize --bg-fill '+ os.environ['HOME'] + '/Imager/'+ f)
        time.sleep(1)
