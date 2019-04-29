import sys
import os
import subprocess

# mk_snsrdt_yr.py
# 時系列に沿ったファイル名で保存されているSenserDataを作る．
# $ python mk_snsrdt_yr.py [ディレクトリ] [年(yyyy)] [１つあたりのデータ量]

# 引数[１つあたりのデータ量]：指定されたデータ量を持ったyyyymmdd_iii.datが生成される
# mm : 01〜12
# dd : 01〜31
# iii : 000〜999
# つまり，１回のプログラムの実行で生成されるデータ量は「[１つあたりのデータ量] * 1000 * 365」である

# （例） $ python mk_snsrdt_yr.py test 2018 1K
# ディレクトリtestの中の2018 (無ければ生成する．)
# その中に， 1日ごとにファイル分けした，
# 1K * 1000 * 365 = 365000KB = 356.445MB = 0.348GB のセンサデータを生成する．

def main():
    args = sys.argv
    mkdt_year(args)

def mkdt_year(args):
    root_dir = args[1]
    yyyy = args[2]
    size = args[3]
    print("Create sensor data (size : " + size + ") for '" + yyyy + "' in '" + root_dir + "'.")

    if not os.path.exists(root_dir):
        run_and_capture("mkdir " + root_dir)
    if not os.path.exists(root_dir + "/" + yyyy):
        run_and_capture("mkdir " + root_dir + "/" + yyyy)
    for mm in range(1, 12):
        if not os.path.exists(root_dir + "/" + yyyy + "/" + str(mm).zfill(2)):
            run_and_capture("mkdir " + root_dir + "/" + yyyy + "/" + str(mm).zfill(2))
        if mm == 4 or mm == 6 or mm == 9 or mm == 11:
            for dd in range(1, 31):
                if not os.path.exists(root_dir + "/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2)):
                    run_and_capture("mkdir " + root_dir + "/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2))
                for iii in range(1000):
                    run_and_capture("dd if=/dev/zero of=test/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2) + "/" + yyyy + str(mm).zfill(2) + str(dd).zfill(2) + "_" + str(iii).zfill(3) + ".dat bs=" + size + " count=1")
        elif mm == 2:
            for dd in range(1, 29):
                if not os.path.exists(root_dir + "/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2)):
                    run_and_capture("mkdir " + root_dir + "/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2))
                for iii in range(1000):
                    run_and_capture("dd if=/dev/zero of=test/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2) + "/" + yyyy + str(mm).zfill(2) + str(dd).zfill(2) + "_" + str(iii).zfill(3) + ".dat bs=" + size + " count=1")
        else: #1,3,5,7,8,10,12
            for dd in range(1, 32):
                if not os.path.exists(root_dir + "/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2)):
                    run_and_capture("mkdir " + root_dir + "/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2))
                for iii in range(1000):
                    run_and_capture("dd if=/dev/zero of=test/" + yyyy + "/" + str(mm).zfill(2) + "/" + str(dd).zfill(2) + "/" + yyyy + str(mm).zfill(2) + str(dd).zfill(2) + "_" + str(iii).zfill(3) + ".dat bs=" + size + " count=1")


def run_and_capture(cmd):
    proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    buf = []

    while True:

        line = proc.stdout.readline()
        buf.append(line)
        sys.stdout.write(line)

        if not line and proc.poll() is not None:
            break

    return ''.join(buf)

if __name__ == '__main__':
    main()
