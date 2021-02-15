class Foo {

    private Semaphore sem_two = new Semaphore(0);
    private Semaphore sem_three = new Semaphore(0);

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        sem_two.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        sem_two.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        sem_three.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        sem_three.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}