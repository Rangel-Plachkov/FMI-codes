package Labs.Lab_6;

public class w6Pr2aTest {
    public  static void main(String[] args){
        long tm = System.currentTimeMillis();
        long ct = tm;
        long et = tm + 90_000;
        while(true) {
            for (w6pr2a t : w6pr2a.values()) {
                System.out.println(t);
                int duration = t.getDuration();
                tm += duration;
                while (ct < tm) {
                    ct = System.currentTimeMillis();
                    if(ct > et){
                        System.exit(0);
                    }
                }
            }
        }
    }
}
