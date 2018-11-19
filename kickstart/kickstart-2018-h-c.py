# encoding: utf-8
"""
@author: pkusp
@contact: pkusp@outlook.com

@version: 1.0
@file: kickstart-2018-h-c.py
@time: 2018/11/18 下午3:10

这一行开始写关于本文件的说明与解释
"""

# global cnt
#
# def count_ways(n,m):
#     res=0
#     total = n
#     new_couple = m
#     old_couple = n - m
#     dfs('o',old_couple,new_couple)
#     return res
#
#
# def dfs(current,old_cnt,new_cnt):
#     if old_cnt==0 and new_cnt==0:
#         cnt+=1
#         return
#     if old_cnt<0:
#         return
#     if new_cnt<0:
#         return
#     if(current=='o'):
#         dfs('o',old_cnt-1,new_cnt)
#         dfs('n',old_cnt-1,new_cnt)
#     else:
#         dfs('o',old_cnt,new_cnt-1)


class CountWays(object):
    def __init__(self):
        self.cnt = 0

    def count_ways(self,n, m):
        new_couple = m
        old_couple = n - m
        # print(old_couple,new_couple)
        self.dfs('empty', old_couple, new_couple)
        return self.cnt % 1000000007

    def dfs(self,current, old_cnt, new_cnt):
        # print(current, old_cnt+new_cnt)
        if old_cnt == 0 and new_cnt == 0:
            self.cnt += 1
            return
        if old_cnt < 0:
            return
        if new_cnt < 0:
            return
        elif current == 'o' or current == 'empty':
            self.dfs('o', old_cnt - 1, new_cnt)
            self.dfs('n', old_cnt, new_cnt - 1)
        else:
            self.dfs('o', old_cnt, new_cnt - 1)


if __name__ == "__main__":
    out_put = []
    with open("C-small-attempt0.in") as f:
        tests = int(f.readline())
        for num in range(tests):
            cntway = CountWays()
            line = f.readline()
            # N = int(line.strip())
            couples = f.readline().split()
            couples = [int(s) for s in couples]
            n,m=couples[0],couples[1]
            out_put.append(cntway.count_ways(2*n,2*m))

    wf = open("C-small.out", "w")
    for i in range(len(out_put)):
        wf.writelines("Case #{0}: {1}\n".format(i + 1, out_put[i]))
    wf.close()
