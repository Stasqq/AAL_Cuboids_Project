import java.util.ArrayList;

public class AlgorithmOutput {
    private double time;
    private int x;
    private int y;
    private int z;
    private ArrayList<Cuboid> cuboids;

    public AlgorithmOutput(double time, int x, int y, int z, ArrayList<Cuboid> cuboids) {
        this.time = time;
        this.x = x;
        this.y = y;
        this.z = z;
        this.cuboids = cuboids;
    }

    public double getTime() {
        return time;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getZ() {
        return z;
    }

    public ArrayList<Cuboid> getCuboids() {
        return cuboids;
    }

    public void print() {
        System.out.println("time: " + time);
        System.out.println("x: " + x);
        System.out.println("y: " + y);
        System.out.println("z: " + z);

        for (Cuboid cuboid : cuboids)
            System.out.println("xSize: " + cuboid.getxSize() + " ,ySize: " + cuboid.getySize() + " ,zSize: " + cuboid.getzSize() +
                    "\nx: " + cuboid.getX() + " ,y: " + cuboid.getY() + " ,z: " + cuboid.getZ() + "\n");
    }
}
