public class TaskThreadDemo{
    public static void main(String[] args) {
        Runnable printA = new PrintChar('a',100);
        Runnable printB = new PrintChar('b',100);

        Thread thread1 = new Thread(printA);
        Thread thread2 = new Thread(printB);

        thread1.start();
        thread2.start();
    }
}

class PrintChar implements Runnable{
    private char charToPrint;
    private int times;

    public PrintChar(char c,int t){
        charToPrint = c;
        times = t;
    }

    @Override
    public void run(){
        for(int i = 0; i < times; i++)
            System.out.print(charToPrint);
    }
}

