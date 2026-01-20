import javax.swing.*;
public class Main{
    public static void main(String[] args) {
        // It is recommended to create and show Swing GUI on the Event Dispatch Thread (EDT)
        SwingUtilities.invokeLater(() -> {
            // 1. Create the JFrame with a title
            JFrame frame = new JFrame("My First Swing Frame");

            // 2. Set the default close operation (exit the application)
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            // 3. Set the size of the frame
            frame.setSize(300, 200);

            // 5. Add a component (a simple label)
            frame.add(new JLabel("Hello, world!"));

            // 6. Make the frame visible
            frame.setVisible(true);

            // Optional: Center the frame on the screen
            frame.setLocationRelativeTo(null);
        });
    }
}
