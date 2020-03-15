## KMP剖析
经过对一些`KMP`原理及算法的阅读，整合出以下内容：

### 1. `next` 数组及其计算
所谓next数组，即字符串前后缀交集的最大长度的值。举例来说，字符串`abc`的前缀为`a` `ab`,后缀为`bc` `c`,交集为空，此时`next`数组为`[0,0,0]`；字符串`aba`的前后缀分别为`a` `ab` 和`ba` `a`，交集为`a` 交集的长度为1,此时`next`数组为`[0,0,1]`.

实现：
```cpp
vector<int> getNext(const string pattern)
{
    int k=0;  //最大前后缀长度
    vector<int> next(m);
    for (int i = 1; i < pattern.size(); ++i)  //从第二个字符开始
    {
        while(k > 0 && pattern[i] != pattern[k]){  //求P[i]的最大相同前后缀长度k，这个地方实际是递归
            // a..bd...a..b c
            // a..b(a'..b'c...a'..b')
            k = next[k-1];   
        }
        if (pattern[i] == pattern[k])//如果相等，那么最大相同前后缀长度加1
        {
            k++;
        }
        next[i] = k;
    }

    return next;
}
```

递归过程：
- *p[j]!=t[i]: 此时(c!=d)*
**(a##b)`d`..(a##b)`c`**
- *将(a--b)展开：此时(c!=x)*
**(a'##b')`x`..(a'##b')**
- *继续将(a'--b')展开：此时(c==c)满足，设以下新c的位置为c'则next[c]=next[c']*
**(a''##b'')`c`..(a''##b'')**

<!--
如果字符串s存在着相等的前缀和后缀（即next[q-1]>0），这个时候我们不需要去回退主串指针，只要把我们的子串往后移动，使得我们字符串s中的前缀和后缀相等的那个前缀移动到后缀的位置处，因为前缀=后缀=主串中的部分串，这样我们直接就将子串定位到了可以进行下一趟比较探测的位置，而没有回退过主串指针。我们希望这个相等的前缀和后缀的长度越大越好（这也是为什么我们next数组中是求相等的前缀和后缀中最长的那个相等串的值），显然这样就可以匹配更多相同的元素。对于上面的例子来说就是，s = abcab，此时前缀和后缀相等的只有ab，也就是我们的next[q-1] = 2；这个时候，我们移动子串，使得我们的前缀ab移动到后缀ab处的位置
-->
### 2. `KMP`算法的实现
其实进行`next`数组求解的过程，类似于主串和子串进行匹配的过程，只不过是在`next`数组求解过程中，是子串和子串自己进行比较而已。这里将求解`next`时的其中之一换位主串`t`个,`KMP`算法的代码过程如下：
```cpp
int KMP(string pattern,string t){
    vector<int> next = getNext(pattern);
    int k=0;
    for(int i=0;i<t.size();++i){
        while(k>0&&pattern[k]!=t[i]){
            k=next[k-1];
        }
        if(pattern[k]==t[i]){
            k++;
        }
        if(k==pattern.size()){
            return i-k+1;
        }
    }
    return -1;
}

```
> 这段代码还没有测试，测试完后更新...

## 参考文献
- [jBoxer博客](http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/)
- [我眼中的KMP](https://blog.csdn.net/shakespeare001/article/details/51381251)
- [next数组图解](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)


