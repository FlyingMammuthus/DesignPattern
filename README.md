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

## 结构型模式

## 行为型模式
