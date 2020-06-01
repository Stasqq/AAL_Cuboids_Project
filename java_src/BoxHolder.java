import javafx.scene.paint.Color;
import javafx.scene.shape.Box;
import javafx.scene.shape.Rectangle;

import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;

public class BoxHolder {
    private Rectangle boxes[][][];
    private ArrayList<Cuboid> cuboids;
    private ArrayList<ArrayList<Rectangle>> levels;
    private ArrayList<ArrayList<Rectangle>> verticals;
    int x, y, z;

    public BoxHolder(int x, int y, int z, ArrayList<Cuboid> cuboids) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.cuboids = cuboids;
        boxes = new Rectangle[x][y][z];
        initiateBoxes();
        initiateLevels();
        initiateVerticals();
    }

    private void initiateBoxes() {
        int xSize, ySize, zSize, x, y, z;
        Color color;
        double r, g, b;
        for (Cuboid cuboid : cuboids) {
            xSize = cuboid.getxSize();
            ySize = cuboid.getySize();
            zSize = cuboid.getzSize();
            x = cuboid.getX();
            y = cuboid.getY();
            z = cuboid.getZ();
            r = ThreadLocalRandom.current().nextDouble(0, 0.8);
            g = ThreadLocalRandom.current().nextDouble(0, 0.8);
            b = ThreadLocalRandom.current().nextDouble(0, 0.8);
            color = new Color(r, g, b, 1);
            for (int i = x; i < x + xSize; i++) {
                for (int j = y; j < y + ySize; j++) {
                    for (int k = z; k < z + zSize; k++) {
                        Rectangle box = new Rectangle(20, 20, color);
                        boxes[i][j][k] = box;
                    }
                }
            }
        }
    }

    private void initiateLevels() {
        levels = new ArrayList<ArrayList<Rectangle>>();
        int layoutY = y * 30;
        for (int k = 0; k < z; k++) {
            ArrayList<Rectangle> level = new ArrayList<Rectangle>();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (boxes[i][j][k] != null) {
                        Rectangle box = new Rectangle(boxes[i][j][k].getWidth(), boxes[i][j][k].getHeight(), boxes[i][j][k].getFill());
                        box.setLayoutX(10 + i * 30);
                        box.setLayoutY(layoutY - (10 + j * 30));
                        level.add(box);
                    } else {
                        Color color = new Color(0.9, 0.9, 0.9, 1);
                        Rectangle box = new Rectangle(20, 20, color);
                        box.setLayoutX(10 + i * 30);
                        box.setLayoutY(layoutY - (10 + j * 30));
                        level.add(box);
                    }
                }
            }
            levels.add(level);
        }
    }

    private void initiateVerticals() {
        verticals = new ArrayList<ArrayList<Rectangle>>();
        int layoutY = z * 30;
        for (int j = 0; j < y; j++) {
            ArrayList<Rectangle> vertical = new ArrayList<Rectangle>();
            for (int i = 0; i < x; i++) {
                for (int k = 0; k < z; k++) {
                    if (boxes[i][j][k] != null) {
                        Rectangle box = new Rectangle(boxes[i][j][k].getWidth(), boxes[i][j][k].getHeight(), boxes[i][j][k].getFill());
                        box.setLayoutX(10 + i * 30);
                        box.setLayoutY(layoutY - (10 + k * 30));
                        vertical.add(box);
                    } else {
                        Color color = new Color(0.9, 0.9, 0.9, 1);
                        Rectangle box = new Rectangle(20, 20, color);
                        box.setLayoutX(10 + i * 30);
                        box.setLayoutY(layoutY - (10 + k * 30));
                        vertical.add(box);
                    }
                }
            }
            verticals.add(vertical);
        }
    }

    public ArrayList<Rectangle> getLevel(int i) {
        return levels.get(i);
    }

    public ArrayList<Rectangle> getVertical(int i) {
        return verticals.get(i);
    }

}
