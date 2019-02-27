# DesignPattern
实现基本的设计模式，给出了相应的C++代码：  
## 创建型模式
1. 简单工厂模式  
又称为静态工厂方法(Static Factory Method)模式，它属于类创建型模式。  
在简单工厂模式中，可以根据参数的不同返回不同类的实例。  
简单工厂模式专门定义一个类来负责创建其他类的实例，被创建的实例通常都具有共同的父类。  
角色：  
Factory类：负责创建具体产品的实例  
Product类：抽象产品类，定义产品子类的公共接口  
ConcreteProduct 类：具体产品类，实现Product父类的接口功能，也可添加自定义的功能  

2. 工厂方法模式  
定义一个创建产品对象的工厂接口，将实际创建工作推迟到子类当中。  
核心工厂类不再负责产品的创建，这样核心类成为一个抽象工厂角色，仅负责具体工厂子类必须实现的接口，  
这样进一步抽象化的好处是使得工厂方法模式可以使系统在不修改具体工厂角色的情况下引进新的产品。  
工厂方法模式是简单工厂模式的衍生，解决了许多简单工厂模式的问题。  
首先完全实现‘开－闭 原则’，实现了可扩展。  
其次更复杂的层次结构，可以应用于产品结果复杂的场合。   
工厂方法模式对简单工厂模式进行了抽象。有一个抽象的Factory类（可以是抽象类和接口），  
这个类将不再负责具体的产品生产，而是只制定一些规范，具体的生产工作由其子类去完成。  
在这个模式中，工厂类和产品类往往可以依次对应。即一个抽象工厂对应一个抽象产品，  
一个具体工厂对应一个具体产品，这个具体的工厂就负责生产对应的产品。  
工厂方法模式(Factory Method pattern)是最典型的模板方法模式(Template Method pattern)应用。  
抽象工厂(Creator)角色：是工厂方法模式的核心，与应用程序无关。任何在模式中创建的对象的工厂类必须实现这个接口。  
具体工厂(Concrete Creator)角色：这是实现抽象工厂接口的具体工厂类，包含与应用程序密切相关的逻辑,并且受到应用程序调用以创建产品对象。   
抽象产品(Product)角色：工厂方法模式所创建的对象的超类型，也就是产品对象的共同父类或共同拥有的接口。  
具体产品(Concrete Product)角色：这个角色实现了抽象产品角色所定义的接口。  
某具体产品有专门的具体工厂创建，它们之间往往一一对应。  

3. 抽象工厂模式  
提供一个创建一系列相关或相互依赖对象的接口，而无须指定它们具体的类。抽象工厂模式又称为Kit模式，属于对象创建型模式。  
此模式是对工厂方法模式的进一步扩展。在工厂方法模式中，一个具体的工厂负责生产一类具体的产品，即一对一的关系，  
但是，如果需要一个具体的工厂生产多种产品对象，那么就需要用到抽象工厂模式了。  
为了便于理解此模式，这里介绍两个概念：  
产品等级结构：产品等级结构即产品的继承结构，如一个抽象类是电视机，其子类有海尔电视机、海信电视机、TCL电视机，  
则抽象电视机与具体品牌的电视机之间构成了一个产品等级结构，抽象电视机是父类，而具体品牌的电视机是其子类。  
产品族 ：在抽象工厂模式中，产品族是指由同一个工厂生产的，位于不同产品等级结构中的一组产品，  
如海尔电器工厂生产的海尔电视机、海尔电冰箱，海尔电视机位于电视机产品等级结构中，海尔电冰箱位于电冰箱产品等级结构中。  
角色：  
抽象工厂（AbstractFactory）：担任这个角色的是抽象工厂模式的核心，是与应用系统的商业逻辑无关的。  
具体工厂（Factory）：这个角色直接在客户端的调用下创建产品的实例，这个角色含有选择合适的产品对象的逻辑，而这个逻辑是与应用系统商业逻辑紧密相关的。  
抽象产品（AbstractProduct）：担任这个角色的类是抽象工厂模式所创建的对象的父类，或它们共同拥有的接口。  
具体产品（Product）：抽象工厂模式所创建的任何产品对象都是一个具体的产品类的实例。  

4. 生成器模式  
是一种对象构建模式。它可以将复杂对象的建造过程抽象出来（抽象类别），使这个抽象过程的不同实现方法可以构造出不同表现（属性）的对象。  
建造者模式是一步一步创建一个复杂的对象，它允许用户只通过指定复杂对象的类型和内容就可以构建它们，  
用户不需要知道内部的具体构建细节。例如，一辆汽车由轮子，发动机以及其他零件组成，对于普通人而言，我们使用的只是一辆完整的车，  
这时，我们需要加入一个构造者，让他帮我们把这些组件按序组装成为一辆完整的车。  
角色：  
Builder：抽象构造者类，为创建一个Product对象的各个部件指定抽象接口。  
ConcreteBuilder：具体构造者类，实现Builder的接口以构造和装配该产品的各个部件。定义并明确它所创建的表示。提供一个检索产品的接口  
Director：指挥者，构造一个使用Builder接口的对象。  
Product：表示被构造的复杂对象。ConcreateBuilder创建该产品的内部表示并定义它的装配过程。  
包含定义组成部件的类，包括将这些部件装配成最终产品的接口。  

5. 单例模式  
也叫单子模式，是一种常用的软件设计模式。在应用这个模式时，单例对象的类必须保证只有一个实例存在。
许多时候整个系统只需要拥有一个的全局对象，这样有利于我们协调系统整体的行为。
实现单例模式的思路是：一个类能返回对象一个引用(永远是同一个)和一个获得该实例的方法
（必须是静态方法，通常使用getInstance这个名称）；当我们调用这个方法时，如果类持有的引用不为空就返回这个引用，
如果类保持的引用为空就创建该类的实例并将实例的引用赋予该类保持的引用；
同时我们还将该类的构造函数定义为私有方法，这样其他处的代码就无法通过调用该类的构造函数来实例化该类的对象，
只有通过该类提供的静态方法来得到该类的唯一实例。

## 结构型模式
6. 适配器模式  
有时候也称包装样式或者包装(wrapper)。将一个类的接口转接成用户所期待的。  
一个适配使得因接口不兼容而不能在一起工作的类工作在一起，做法是将类自己的接口包裹在一个已存在的类中。  
顾名思义，此模式是源于类似于电源适配器的设计和编码技巧。比如现在有一些类，提供一些可用的接口，  
但是可能客户端因为不兼容的原因，不能直接调用这些现有的接口，这时就需要一个适配器来作为中转站，  
适配器类可以向用户提供可用的接口，其内部将收到的请求转换为对适配者对应接口的真是请求，从而实现对不兼容的类的复用。  
优点：将目标类和适配者类解耦，通过引入一个适配器类来重用现有的适配者类，而无须修改原有代码。  
增加了类的透明性和复用性，将具体的实现封装在适配者类中，对于客户端类来说是透明的，而且提高了适配者的复用性。  
角色：   
Target：目标抽象类  
Adapter：适配器类  
Adaptee：适配者类  
Client：客户类。    

7. 桥接模式  
软件设计模式中最复杂的模式之一，它把事物对象和其具体行为、具体特征分离开来，使它们可以各自独立的变化。  
事物对象仅是一个抽象的概念。如“圆形”、“三角形”归于抽象的“形状”之下，而“画圆”、  
“画三角”归于实现行为的“画图”类之下，然后由“形状”调用“画图”。  
理解桥接模式，重点需要理解如何将抽象化(Abstraction)与实现化(Implementation)脱耦，  
使得二者可以独立地变化。桥接模式提高了系统的可扩充性，  
在两个变化维度中任意扩展一个维度，都不需要修改原有系统。  
角色：    
Abstraction：定义抽象的接口，该接口包含实现具体行为、具体特征的Implementor接口  
Refined Abstraction：抽象接口Abstraction的子类，依旧是一个抽象的事物名  
Implementor：定义具体行为、具体特征的应用接口  
ConcreteImplementor：实现Implementor接口  

8. 修饰模式  
面向对象编程领域中，一种动态地往一个类中添加新的行为的设计模式。  
就功能而言，修饰模式相比生成子类更为灵活，这样可以给某个对象而不是整个类添加一些功能。   
一般来说，给一个对象或者类增加行为的方式可以有两种：  
继承机制，使用继承机制是给现有类添加功能的一种有效途径，通过继承一个现有类可以使得子类在拥有自身方法的同时还拥有父类的方法。  
但是这种方法是静态的，用户不能控制增加行为的方式和时机。  
关联机制，即将一个类的对象嵌入另一个对象中，由另一个对象来决定是否调用嵌入对象的行为以便扩展自己的行为，  
我们称这个嵌入的对象为装饰器(Decorator)  
通过使用修饰模式，可以在运行时扩充一个类的功能。原理是：增加一个修饰类包裹原来的类，  
包裹的方式一般是通过在将原来的对象作为修饰类的构造函数的参数。装饰类实现新的功能，  
但是，在不需要用到新功能的地方，它可以直接调用原来的类中的方法。修饰类必须和原来的类有相同的接口。  
修饰模式是类继承的另外一种选择。类继承在编译时候增加行为，而装饰模式是在运行时增加行为。  
角色  
Component: 抽象构件  
ConcreteComponent: 具体构件  
Decorator: 抽象装饰类  
ConcreteDecorator: 具体装饰类  

9. 外观模式  
外观模式(Facade Pattern)：外部与一个子系统的通信必须通过一个统一的外观对象进行，  
为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。  
外观模式又称为门面模式，它是一种对象结构型模式。  
举一个简单的例子，相信大家都使用过 C++ 语言，他是一门编译型语言，写完代码之后，  
我们需要经过编译之后才能运行，在IDE中，会有一个 Build 的按钮，点击它即可完成编译过程，  
但是这一个简单的动作背后，却是一系列复杂操作的协调配合，至少包括词法分析，语法分析，生成中间代码，  
生成汇编代码以及链接等操作，作为普通开发人员，我们不必在意这些过程是如何完成的，只需要点击Build按钮，  
IDE就会自动帮我们完成背后的工作。那么这个Build按钮就是IDE为我们提供的高级接口，  
通过他来完成各种子系统的协调工作。  
角色：  
Facade：外观角色，提供高级接口  
SubSystem：子系统角色，负责各自的功能实现  

10. 享元模式  
享元模式（Flyweight Pattern）是一种软件设计模式。  
它使用共享物件，用来尽可能减少内存使用量以及分享资讯给尽可能多的相似物件；  
它适合用于当大量物件只是重复因而导致无法令人接受的使用大量内存。  
通常物件中的部分状态是可以分享。常见做法是把它们放在外部数据结构，  
当需要使用时再将它们传递给享元。由于享元模式要求能够共享的对象必须是细粒度对象，  
因此它又称为轻量级模式，它是一种对象结构型模式。  
要理解享元模式，先要理解两个重要的概念：内部状态和外部状态。  
内部状态存储于flyweight中，它包含了独立于flyweight场景的信息，这些信息使得flyweight可以被共享。  
而外部状态取决于flyweight场景，并根据场景而变化，因此不可共享。用户对象负责在必要的时候将外部状态传递给flyweight。  
角色  
Flyweight： 抽象享元类  
ConcreteFlyweight： 具体享元类  
UnsharedConcreteFlyweight： 非共享具体享元类  
FlyweightFactory： 享元工厂类  

## 行为型模式
