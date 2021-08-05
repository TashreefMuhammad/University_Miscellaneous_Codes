package producerconsumerproblem;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Producer implements Runnable {

    @Override
    public void run() {
        // Calling the produce method which will take care of the rest
        produce();
    }

    private void produce() {
        // Values to be entered in the buffer
        int val = 0;
        while (true) {
            try {
                // To control whether to wait, or keep on production
                while (ProducerConsumerProblem.buffer.size() == ProducerConsumerProblem.buffSize) {
                    synchronized (ProducerConsumerProblem.buffer) {
                        ProducerConsumerProblem.buffer.wait();
                    }
                }

                // Produce and store new values in the queue
                synchronized (ProducerConsumerProblem.buffer) {
                    System.out.println("Producer produced: " + val);
                    ProducerConsumerProblem.buffer.add(val++);
                    System.out.println("Current size of Buffer: " + ProducerConsumerProblem.buffer.size() + "\n");

                    ProducerConsumerProblem.buffer.notifyAll();
                }
                
                // Create a random number from 100 till 999. This will be sleep time denoting time needed before another produce entry
                Random rand = new Random();
                Thread.sleep(rand.nextInt(1000 - 100) + 100);
            } catch (InterruptedException ex) {
                Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
