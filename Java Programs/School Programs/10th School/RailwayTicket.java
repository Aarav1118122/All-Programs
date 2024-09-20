import java.util.*;

public class RailwayTicket {
    String name;
    String coach;
    long mobno;
    int amt;
    int totalamt;

    public static void main(String[] args) {
        accept();
        update();
        display();
    }

    public static void accept() {
        Scanner sc = new Scanner(System.in);
        RailwayTicket ticket = new RailwayTicket();
        ticket.name = sc.next();
        ticket.coach = sc.next();
        ticket.mobno = sc.nextLong();
        ticket.amt = sc.nextInt();
        ticket.totalamt = sc.nextInt();
    }

    public static void update() {

    }

    public static void display() {

    }
}