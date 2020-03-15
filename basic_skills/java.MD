# Java笔记  
> 出处：[runoob](https://www.runoob.com/java/java-tutorial.html)  
> 时间：2020.02

## 1. 入门
### 简介
Java是由Sun Microsystems公司于1995年5月推出的Java面向对象程序设计语言和Java平台的总称。由James Gosling和同事们共同研发，并在1995年正式推出。
- 开发工具：eclipse
- 配置
    - JDK
    - 环境变量

### hello world 
创建文件 HelloWorld.java(文件名需与类名一致),
```c
//注：String args[] 与 String[] args 都可以执行，但推荐使用 String[] args，这样可以避免歧义和误读。
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}

//$ javac HelloWorld.java
//$ java HelloWorld
// Hello World
以上我们使用了两个命令 javac 和 java。
javac 后面跟着的是java文件的文件名，例如 HelloWorld.java。 该命令用于将 java 源文件编译为 class 字节码文件，如： javac HelloWorld.java。
运行javac命令后，如果成功编译没有错误的话，会出现一个 HelloWorld.class 的文件。
java 后面跟着的是java文件中的类名,例如 HelloWorld 就是类名，如: java HelloWorld
```
## 2. 基础语法
一个 Java 程序可以认为是一系列对象的集合，而这些对象通过调用彼此的方法来协同工作。下面简要介绍下类、对象、方法和实例变量的概念。

- 对象：对象是类的一个实例，有状态和行为。例如，一条狗是一个对象，它的状态有：颜色、名字、品种；行为有：摇尾巴、叫、吃等。
- 类：类是一个模板，它描述一类对象的行为和状态。
- 方法：方法就是行为，一个类可以有很多方法。逻辑运算、数据修改以及所有动作都是在方法中完成的。
实例变量：每个对象都有独特的实例变量，对象的状态由这些实例变量的值决定。

编写 Java 程序时，应注意以下几点：

- 大小写敏感：Java 是大小写敏感的，这就意味着标识符 Hello 与 hello 是不同的。
- 类名：对于所有的类来说，类名的首字母应该大写。如果类名由若干单词组成，那么每个单词的首字母应该大写，例如 MyFirstJavaClass 。
- 方法名：所有的方法名都应该以小写字母开头。如果方法名含有若干单词，则后面的每个单词首字母大写。
- 源文件名：源文件名必须和类名相同。当保存文件的时候，你应该使用类名作为文件名保存（切记 Java 是大小写敏感的），文件名的后缀为 .java。（如果文件名和类名不相同则会导致编译错误）。
- 主方法入口：所有的 Java 程序由 public static void main(String []args) 方法开始执行。
### Java标识符
Java 所有的组成部分都需要名字。类名、变量名以及方法名都被称为标识符。

- 所有的标识符都应该以字母（A-Z 或者 a-z）,美元符（$）、或者下划线（_）开始
首字符之后可以是字母（A-Z 或者 a-z）,美元符（$）、下划线（_）或数字的任何字符组合
- 关键字不能用作标识符
- 标识符是大小写敏感的
- 合法标识符举例：age、$salary、_value、__1_value
- 非法标识符举例：123abc、-salary
### Java修饰符
像其他语言一样，Java可以使用修饰符来修饰类中方法和属性。主要有两类修饰符：

- 访问控制修饰符 : default, public , protected, private
- 非访问控制修饰符 : final, abstract, static, synchronized

### Java 变量
Java 中主要有如下几种类型的变量
- 局部变量
- 类变量（静态变量）
- 成员变量（非静态变量）

### Java 数组
数组是储存在堆上的对象，可以保存多个同类型变量。

### Java 枚举
Java 5.0引入了枚举，枚举限制变量只能是预先设定好的值。使用枚举可以减少代码中的 bug。
```java
// 例如，我们为果汁店设计一个程序，它将限制果汁为小杯、中杯、大杯。这就意味着它不允许顾客点除了这三种尺寸外的果汁。


class FreshJuice {
   enum FreshJuiceSize{ SMALL, MEDIUM , LARGE }
   FreshJuiceSize size;
}
 
public class FreshJuiceTest {
   public static void main(String []args){
      FreshJuice juice = new FreshJuice();
      juice.size = FreshJuice.FreshJuiceSize.MEDIUM  ;
   }
}
//注意：枚举可以单独声明或者声明在类里面。方法、变量、构造函数也可以在枚举中定义。

```

### Java 关键字
下面列出了 Java 关键字。这些保留字不能用于常量、变量、和任何标识符的名称。
```java
类别	关键字	说明
// 访问控制	
private	私有的
protected	受保护的
public	公共的
类、方法和变量修饰符	abstract	声明抽象
class	类
extends	扩充,继承
final	最终值,不可改变的
implements	实现（接口）
interface	接口
native	本地，原生方法（非 Java 实现）
new	新,创建
static	静态
strictfp	严格,精准
synchronized	线程,同步
transient	短暂
volatile	易失

// 程序控制语句	
break	跳出循环
case	定义一个值以供 switch 选择
continue	继续
default	默认
do	运行
else	否则
for	循环
if	如果
instanceof	实例
return	返回
switch	根据值选择执行
while	循环
// 错误处理	
assert	断言表达式是否为真
catch	捕捉异常
finally	有没有异常都执行
throw	抛出一个异常对象
throws	声明一个异常可能被抛出
try	捕获异常
//包相关	
import	引入
package	包
//基本类型	
boolean	布尔型
byte	字节型
char	字符型
double	双精度浮点
float	单精度浮点
int	整型
long	长整型
short	短整型
//变量引用	
super	父类,超类
this	本类
void	无返回值
//保留关键字	
goto	是关键字，但不能使用
const	是关键字，但不能使用
null	空
```