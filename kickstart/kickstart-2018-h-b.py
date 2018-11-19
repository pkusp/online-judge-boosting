# encoding: utf-8
"""
@author: pkusp
@contact: pkusp@outlook.com

@version: 1.0
@file: kickstart-2018-h-b.py
@time: 2018/11/18 下午2:12

这一行开始写关于本文件的说明与解释
"""


def mural(scores):
    sum = 0
    hn = len(scores) // 2 + len(scores) % 2
    for i in range(hn):
        sum += scores[i]
    res = sum
    for i in range(len(scores) - hn):
        sum = sum - scores[i] + scores[i + hn]
        res = max(res, sum)
    return res


if __name__ == "__main__":
    out_put = []
    with open("B-large.in") as f:
        tests = int(f.readline())
        for num in range(tests):
            line = f.readline()
            N = int(line.strip())
            scores = f.readline().strip()
            scores = [int(s) for s in list(scores)]
            out_put.append(mural(scores))

    wf = open("B-large.out", "w")
    for i in range(len(out_put)):
        wf.writelines("Case #{0}: {1}\n".format(i + 1, out_put[i]))
    wf.close()
