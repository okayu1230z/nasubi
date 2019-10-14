# -*- coding: utf-8 -*-
import sys
import re
import codecs

def dd_log(logname):
    tp = []
    flag = ""
    with open(logname) as f:
        slist = f.readlines()
        for sl in slist:
            if 'copied' in sl:
                words = re.split(" +", sl.split(",")[-1])
                if flag == "":
                    if "MB" in words[2]:
                        flag = "M"
                    elif "kB" in words[2]:
                        flag = "k"
                tp.append(float(words[1]))

        sum = 0
        for i in tp:
            sum += i

        ave =  sum / len(tp)


        if flag == "M":
            print("Ave(MB/s) : " + str(ave))
            print("Ave(Mbps) : " + str(ave * 8))
        elif flag == "k":
            print("Ave(kB/s) : " + str(ave))
            print("Ave(Mbps) : " + str(ave * 8 * 0.001))
        else:
            print("in else")

        

if __name__ == '__main__':
    args = sys.argv
    dd_log(args[1])
