## KMP剖析
经过对一些`KMP`原理及算法的阅读，整合出以下内容：

### 1. `next` 数组及其计算
所谓next数组，即字符串前后缀交集的最大长度的值

实现：
```cpp
vector<int> makeNext(const string pattern)
{
    int k=0;//k:最大前后缀长度
    vector<int> next(m);
    for (int i = 1; i < pattern.size(); ++i)//for循环，从第二个字符开始
    {
        while(k > 0 && pattern[i] != pattern[k]){  //求P[i]的最大相同前后缀长度k
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
