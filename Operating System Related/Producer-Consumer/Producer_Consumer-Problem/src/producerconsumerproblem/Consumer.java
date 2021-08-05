package producerconsumerproblem;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Consumer implements Runnable {

    @Override
    public void run() {
        // Calling the consumer method which will take care of the rest
        consume();
    }

    private void consume() {
        // Values to be removed in the buffer
        int val;
        while (true) {
            try {
                // To control whether to wait, or keep on consuming
                while (ProducerConsumerProblem.buffer.isEmpty()) {
                    synchronized (ProducerConsumerProblem.buffer) {
                        ProducerConsumerProblem.buffer.wait();
                    }
                }
                
                // Consume existing values from the queue
                synchronized (ProducerConsumerProblem.buffer) {

                    val = ProducerConsumerProblem.buffer.remove();
                    System.out.println("Consumer consumed: " + val + "\nCurrent size of Buffer: " + ProducerConsumerProblem.buffer.size() + "\n");

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
