/**
 * Created by xl on 2017/4/19.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
public class Server {
    public static void main(String[] args) throws IOException {
        //为了简单起见，所有的异常信息都往外抛
        int port = 8888;
        //定义一个ServerSocket监听在端口8888上
        ServerSocket server = new ServerSocket(port);
        while (true) {
            //server尝试接收其他Socket的连接请求，server的accept方法是阻塞式的
            Socket socket = server.accept();
            //每接收到一个Socket就建立一个新的线程来处理它
            new Thread(new Task(socket)).start();
        }
    }


    static class Task implements Runnable {

        private Socket socket;

        public Task(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try {
                handleSocket();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        /**
         * 跟客户端Socket进行通信
         *
         * @throws Exception
         */
        private void handleSocket() throws Exception {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream());
            System.out.println(socket.getInetAddress());
            while (true) {
                String str = in.readLine();
                System.out.println(str);
                out.println("has receive...");
                out.flush();
                if (str.equals("end"))
                    break;
            }
            socket.close();
        }

    }
}