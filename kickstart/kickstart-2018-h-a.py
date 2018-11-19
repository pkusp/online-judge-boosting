# encoding: utf-8
"""
@author: pkusp
@contact: pkusp@outlook.com

@version: 1.0
@file: kickstart-2018-h-a.py
@time: 2018/11/18 下午1:17

这一行开始写关于本文件的说明与解释
"""


def big_buttons(n,p,plst):
    plst = sorted(plst,key=lambda x:len(x))
    p_len = len(plst)
    to_del=[]
    for i in range(p_len):
        for j in range(i+1,p_len):
            if is_head(plst[i],plst[j]):
                to_del.append(j)
    to_del = sorted(list(set(to_del)))
    print(to_del)
    for j in to_del[::-1]:
        print(j)
        del plst[j]
    cnt=0
    for pp in plst:
        len_p = len(pp)
        cnt += 2**(n-len_p)
    return 2**(n)-cnt


def is_head(s1,s2):
    assert len(s1)<=len(s2)
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            return False
    return True


if __name__ == "__main__":
    out_put=[]
    with open("A-large.in") as f:
        tests = int(f.readline())
        tinput_number = []
        tinput_prefix = []
        for num in range(tests):
            line = f.readline()
            N, P = line.split(" ")
            N = int(N)
            P = int(P)
            tinput_number.append([N, P])
            prefix_list = []
            for in_num in range(P):
                prefix = f.readline()
                prefix = prefix.strip()
                prefix_list.append(prefix)
            # tinput_prefix.append(prefix_list)
            out_put.append(big_buttons(N,P,prefix_list))

    # print(out_put)

    # output = big_buttons(tinput_number, tinput_prefix)
    wf = open("A-large.out", "w")
    for i in range(len(out_put)):
        wf.writelines("Case #{0}: {1}\n".format(i+1, out_put[i]))
    wf.close()


