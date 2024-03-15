import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.nio.channels.Channels;
import java.nio.channels.SocketChannel;
import java.util.Scanner;

public class Client {
    private static final int SERVER_PORT = 8080;
    private static final int BUFFER_SIZE = 8192;


    public static void main(String[] args) {

        try (SocketChannel socketChannel = SocketChannel.open();
             BufferedReader reader = new BufferedReader(Channels.newReader(socketChannel, "UTF-8"));
             PrintWriter writer = new PrintWriter(Channels.newWriter(socketChannel, "UTF-8"), true);
             Scanner scanner = new Scanner(System.in)) {

            socketChannel.connect(new InetSocketAddress("localhost", SERVER_PORT));

            System.out.println("Connected to the server.");

            while (true) {
                System.out.print("Enter message: ");
                String message = scanner.nextLine();

                if ("quit".equals(message)) {
                    break;
                }

                writer.println(message);

                char[] cbuf = new char[BUFFER_SIZE];
                int length = reader.read(cbuf, 0, cbuf.length);
                if (length != -1) {
                    String reply = new String(cbuf, 0, length);
                    System.out.println(reply);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(
                "Unable to connect to the server." + e.getMessage(), e);
        }
    }

}
