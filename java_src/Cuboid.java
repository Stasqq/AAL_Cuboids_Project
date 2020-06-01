import javafx.scene.paint.Color;

public class Cuboid {
    private int x, y, z, xSize, ySize, zSize;
    private Color color;

    public Cuboid(int xSize, int ySize, int zSize, int x, int y, int z, Color color) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.xSize = xSize;
        this.ySize = ySize;
        this.zSize = zSize;
        this.color = color;
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

    public int getxSize() {
        return xSize;
    }

    public int getySize() {
        return ySize;
    }

    public int getzSize() {
        return zSize;
    }

    public Color getColor() {
        return color;
    }
}
