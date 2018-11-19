# encoding: utf-8
"""
@author: pkusp
@contact: pkusp@outlook.com

@version: 1.0
@file: kmp.py
@time: 2018/11/19 下午3:37

这一行开始写关于本文件的说明与解释
"""


def str_match(p,t):
    p_len = len(p)
    t_len = len(t)
    for i in range(t_len - p_len+1):
        for j in range(p_len):
            if t[i+j] != p[j]:
                break
            if t[i+j] == p[j] and j==p_len-1:
                return i
    return -1

def get_next(pattern):
    k=0
    next = [0]*len(pattern)
    for i in range(1,len(pattern)):
        while k>0 and pattern[i] != pattern[k]:
            k= next[k-1]
        if pattern[i] == pattern[k]:
            k+=1
        next[i] = k
    return next



if __name__ == '__main__':
    pp = 'abcab'
    # tt = 'abc'
    # pos = str_match(pp,tt)
    # print(pos)
    next = get_next(pp)
    print("next:",next)
