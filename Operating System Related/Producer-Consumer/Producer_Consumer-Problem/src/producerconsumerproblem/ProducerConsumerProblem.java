package producerconsumerproblem;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ProducerConsumerProblem {

    public static int buffSize;
    public static Queue<Integer> buffer = new LinkedList<>();
    
    public static void main(String[] args) {
        
        // Taking user input on what will be the size of the buffer
        System.out.println("Enter the required Buffer Size: ");
        Scanner sc = new Scanner(System.in);
        buffSize = sc.nextInt();
        
        /*
        ** Initializing 3 threads to be used.
        ** 1. stoppingThread -> A thread to stop the program execution on user's command
        ** 2. producerThread -> The thread to handle producer thread
        ** 3. consumerThread -> The thread to handle consumer thread
        */
        
        Thread stoppingThread = new Thread(new Stopping());
        Thread producerThread = new Thread(new Producer());
        Thread consumerThread = new Thread(new Consumer());
        
        // Start the threads
        producerThread.start();
        consumerThread.start();
        stoppingThread.start();
    }
}
