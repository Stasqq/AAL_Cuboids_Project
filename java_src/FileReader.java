import javafx.scene.paint.Color;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class FileReader {
    private File file;

    public FileReader(String fileName) {
        this.file = new File(fileName);
    }

    public AlgorithmOutput readFile() {
        int x, y, z;
        double time;
        ArrayList<Cuboid> cuboids = new ArrayList<Cuboid>();
        try {
            Scanner scanner = new Scanner(file);
            if (scanner.hasNextLine()) {
                NumberFormat format = NumberFormat.getInstance(Locale.ENGLISH);
                Number number = format.parse(scanner.nextLine());
                time = number.doubleValue();
            } else
                return null;
            if (scanner.hasNextLine()) {
                x = scanner.nextInt();
                y = scanner.nextInt();
                z = scanner.nextInt();
            } else
                return null;
            while (scanner.hasNext()) {
                cuboids.add(new Cuboid(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), Color.color(Math.random(), Math.random(), Math.random())));
            }

            return new AlgorithmOutput(time, x, y, z, cuboids);
        } catch (FileNotFoundException | ParseException e) {
            e.printStackTrace();
        }
        return null;
    }
}
