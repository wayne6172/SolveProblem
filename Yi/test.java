/**
 * 問：this跟super差在?
 * 
 * 這問題不錯，但牽扯到繼承的觀念，所以解釋起來會需要費點功夫，仔細想想吧
 * 
 * 假設以下有個類別A與類別B，並以#1,#2,#3順序閱讀下列程式碼
*/


class A{
    public int num;
    public void print(){
        System.out.println("I am class A! num is " + this.num);
    }

    public A(int num){
        this.num = num;     //#1 為何需要this，有時也是為了區分誰是這個class的成員(又稱member)，誰是參數
                            //如果變成 num = num，就可能導致無法預期的變數轉移，故為了增進可讀性，才加
    }
}

class B extends A{
    public int num;         //#5 此時又有一個num ，跟A的互相衝突了，這種狀況會比較棘手，而企業上比較罕見這種寫法
    public void print(){
        System.out.println("I am class B! num is " + this.num);     
                            //#6 此時會到這裡，印出了"I am class B! num is 7"
        super.print();      //那麼為何？在物件導向的觀念中，若名子有衝突則以目前類別為最優先，再找父類別，再找祖父類別
                            //以此類推...
    }                       //那這個super.print()是? 其實就是呼叫A的print，這在main是沒辦法做到的(呼叫)
                            //所以會跑到A類別的print，印出"I am class A! num is 2"
                            //等等，為何是 2? 不是應該是7嗎?
                            //原因在即使撞名，num依然可以區分成不同兩個，但如果在類別外意圖取得num則...(可先參考#7)
                            //但此時，呼叫了super.print()，去到了類別"A"之中，因為之前B對A的建構子減去了5(在#2)
                            //所以對於A來說，他的num會是2，所以在類別"A"之中的print，num會顯示2

    public B(int num){
        super(num - 5);     //#2 這裡super是為了呼叫A的建構子，可以想像A是B的子集合，一定要先有A才能再有B
        this.num = num;     //所以通常super一定要放在建構子的第一行(除非有額外特殊需要)，而且參數要符合A的建構子
    }
}

public class test{
    public static void main(String[] args) {
        A a = new A(5);     
        a.print();          //#3 這裡會印出 I am class A! num is 5，應該沒甚麼問題

        B b = new B(7);     //#4 這裡可就麻煩了，請先看完#5再回來
        b.print();          //那麼有2個num，雖然B繼承了A，那麼num會只有一個嗎? 還是各有區分? 
                            //而問題又來了，類別A跟類別B也有print()，只是內容不一樣，這樣呼叫，會跑...?
                            //我們實際跑print看看(請看#6)
        System.out.println("In the main function b.num is " + b.num);
                            // #7 在撞名的情況下，取得b的num，會以最子類別的num優先，故為7
    }
}

/*
    結論：this與super的差異其實我認為是"區分"，雖然業界會盡可能避免相同變數，但有時候為了架構考量
    變數或函數名稱會相同，所以才有this與super

    this.XXX 是存取在"目前"類別中的所有member與function，而super.XXX則是存取"父類別"的member與function
    而通常比較不會有super.print()，那樣的寫法，super比較常見於建構子上(因為為了先建構父類別)
    
    而如果再考慮protected(非public)，即overriding觀念的話，會更複雜，再此先不討論
*/

/*
    程式輸出應為...

    I am class A! num is 5
    I am class B! num is 7
    I am class A! num is 2
    In the main function b.num is 7
*/