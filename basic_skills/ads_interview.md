## skills for ml interview on ads

### must
- coding 
    - leetcode 100 
    - knapsack

- ml
    - lr
    - feature engineering 
    - decision tree
    - random forest
    - gbdt
    - xgboost
    - lightgbm

- application
    - ip (feature,)
        - FM
    - ia(场景优化)
    - cust modeling
        - feature
        - problem(sample，nan，)


### prefer
    - leetcode ++
    - deepctr 
    - deep learning network of ctr 
    - rank model 
    - gnn(deepwalk-gcn)
    - [w2v](https://mp.weixin.qq.com/s/g4P770TJdu2xtP_RMf03QQ)
    - ab test



### plus
- cia
- reignforcement learning
- casual inference 


# basic skills

[FM paper](https://www.csie.ntu.edu.tw/~b97053/paper/Rendle2010FM.pdf)

[CART](https://www.cnblogs.com/keye/p/10564914.html)
[CART-zhihu](https://zhuanlan.zhihu.com/p/36108972)






# plus
- [pre-train history](https://zhuanlan.zhihu.com/p/49271699?utm_source=wechat_session&utm_medium=social&utm_oi=672367944395264000)
    - fine-tuning vs frozen
    - w2v
    - ELMO(embedding from language model)
    训练好这个网络后，输入一个新句子 [公式] ，句子中每个单词都能得到对应的`三个Embedding`:最底层是单词的Word Embedding，往上走是第一层双向LSTM中对应单词位置的Embedding，这层编码单词的句法信息更多一些；再往上走是第二层LSTM中对应单词位置的Embedding，这层编码单词的语义信息更多一些。
    - GPT(generative pre-train)
    GPT也采用两阶段过程，第一个阶段是利用语言模型进行预训练，第二阶段通过Fine-tuning的模式解决下游任务。上图展示了GPT的预训练过程，其实和ELMO是类似的，主要不同在于两点：首先，特征抽取器不是用的RNN，而是用的`Transformer`，上面提到过它的特征抽取能力要强于RNN，这个选择很明显是很明智的；其次，GPT的预训练虽然仍然是以语言模型作为目标任务，但是采用的是`单向的语言模型`，所谓“单向”的含义是指：语言模型训练的任务目标是根据 [公式] 单词的上下文去正确预测单词 [公式] ， [公式] 之前的单词序列Context-before称为上文，之后的单词序列Context-after称为下文。ELMO在做语言模型预训练的时候，预测单词 [公式] 同时使用了上文和下文，而GPT则只采用Context-before这个单词的上文来进行预测，而抛开了下文。这个选择现在看不是个太好的选择，原因很简单，它没有把单词的下文融合进来，这限制了其在更多应用场景的效果，比如阅读理解这种任务，在做任务的时候是可以允许同时看到上文和下文一起做决策的。如果预训练时候不把单词的下文嵌入到Word Embedding中，是很吃亏的，白白丢掉了很多信息。
    - BERT
        - NLP四大任务
        一类是`序列标注`，这是最典型的NLP任务，比如中文分词，词性标注，命名实体识别，语义角色标注等都可以归入这一类问题，它的特点是句子中每个单词要求模型根据上下文都要给出一个分类类别。第二类是`分类`任务，比如我们常见的文本分类，情感计算等都可以归入这一类。它的特点是不管文章有多长，总体给出一个分类类别即可。第三类任务是`句子关系判断`，比如Entailment，QA，语义改写，自然语言推理等任务都是这个模式，它的特点是给定两个句子，模型判断出两个句子是否具备某种语义关系；第四类是`生成式任务`，比如机器翻译，文本摘要，写诗造句，看图说话等都属于这一类。它的特点是输入文本内容后，需要自主生成另外一段文字。
        - bert
        Bert其实和ELMO及GPT存在千丝万缕的关系，比如如果我们把GPT预训练阶段换成双向语言模型，那么就得到了Bert；而如果我们把ELMO的特征抽取器换成Transformer，那么我们也会得到Bert。所以你可以看出：Bert最关键两点，一点是特征抽取器采用Transformer；第二点是预训练的时候采用双向语言模型。
            - masked双向语言模型
            Masked双向语言模型向上图展示这么做：随机选择语料中15%的单词，把它抠掉，也就是用[Mask]掩码代替原始单词，然后要求模型去正确预测被抠掉的单词。但是这里有个问题：训练过程大量看到[mask]标记，但是真正后面用的时候是不会有这个标记的，这会引导模型认为输出是针对[mask]这个标记的，但是实际使用又见不到这个标记，这自然会有问题。为了避免这个问题，Bert改造了一下，15%的被上天选中要执行[mask]替身这项光荣任务的单词中，只有80%真正被替换成[mask]标记，10%被狸猫换太子随机替换成另外一个单词，10%情况这个单词还待在原地不做改动。这就是Masked双向语音模型的具体做法。
            - next sentence prediction
            “Next Sentence Prediction”，指的是做语言模型预训练的时候，分两种情况选择两个句子，一种是选择语料中真正顺序相连的两个句子；另外一种是第二个句子从语料库中抛色子，随机选择一个拼到第一个句子后面。我们要求模型除了做上述的Masked语言模型任务外，附带再做个句子关系预测，判断第二个句子是不是真的是第一个句子的后续句子。之所以这么做，是考虑到很多NLP任务是句子关系判断任务，单词预测粒度的训练到不了句子关系这个层级，增加这个任务有助于下游句子关系判断任务。所以可以看到，它的预训练是个多任务过程。这也是Bert的一个创新






