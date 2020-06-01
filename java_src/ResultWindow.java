import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.layout.AnchorPane;
import javafx.scene.shape.Box;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.awt.*;

public class ResultWindow extends Application {

    private AlgorithmOutput algorithmOutput;
    private AnchorPane anchorPane;
    private Label time;
    private Label dimensions;
    private Spinner<Integer> spinner;
    private Slider slider;
    private ComboBox<String> comboBox;
    private SpinnerValueFactory<Integer> levelValueFactory;
    private BoxHolder boxHolder;
    private String viewMode;
    private ScrollPane scrollPane;


    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        FileReader fileReader = new FileReader(primaryStage.getTitle());
        algorithmOutput = fileReader.readFile();
        boxHolder = new BoxHolder(algorithmOutput.getX(), algorithmOutput.getY(), algorithmOutput.getZ(), algorithmOutput.getCuboids());

        Parent root = FXMLLoader.load(getClass().getResource("result_window.fxml"));
        scrollPane = (ScrollPane) root.lookup("#scroll_pane");

        time = (Label) root.lookup("#time");
        time.setText(String.valueOf(algorithmOutput.getTime()));

        dimensions = (Label) root.lookup("#dimensions");
        dimensions.setText(algorithmOutput.getX() + " x " + algorithmOutput.getY() + " x " + algorithmOutput.getZ());

        spinner = (Spinner<Integer>) root.lookup("#spinner");
        slider = (Slider) root.lookup("#slider");
        slider.setDisable(true);
        spinner.setDisable(true);
        slider.setMin(1);

        slider.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
                spinner.getValueFactory().setValue(newValue.intValue());
                if(viewMode.equals("Poziomo")){
                    changeView(1,newValue.intValue()-1);
                }else{
                    changeView(2,newValue.intValue()-1);
                }
            }
        });

        spinner.valueProperty().addListener(new ChangeListener<Integer>() {
            @Override
            public void changed(ObservableValue<? extends Integer> observable, Integer oldValue, Integer newValue) {
                slider.setValue(spinner.getValue());
                if(viewMode.equals("Poziomo")){
                    changeView(1,newValue-1);
                }else{
                    changeView(2,newValue-1);
                }
            }
        });

        spinner.setEditable(true);

        comboBox = (ComboBox<String>) root.lookup("#combo_box");
        comboBox.getItems().addAll("Poziomo", "Pionowo");
        comboBox.valueProperty().addListener(new ChangeListener<String>() {
            @Override
            public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
                if(newValue.equals("Poziomo")){
                    viewMode = newValue;
                    levelValueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(1,algorithmOutput.getZ(),1);
                    slider.setMax(algorithmOutput.getZ());
                    changeView(1,0);
                }else{
                    viewMode = newValue;
                    levelValueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(1,algorithmOutput.getY(),1);
                    slider.setMax(algorithmOutput.getY());
                    changeView(2,0);
                }
                spinner.setValueFactory(levelValueFactory);
                slider.setDisable(false);
                spinner.setDisable(false);
            }
        });

        scrollPane.setContent(anchorPane);

        primaryStage.setResizable(false);
        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void changeView(int mode, int value) {
        scrollPane.setContent(null);
        anchorPane = new AnchorPane();
        if (mode == 1) {
            for (Rectangle rectangle : boxHolder.getLevel(value)) {
                anchorPane.getChildren().add(rectangle);
            }
        } else if (mode == 2) {
            for (Rectangle rectangle : boxHolder.getVertical(value)) {
                anchorPane.getChildren().add(rectangle);
            }
        }
        scrollPane.setContent(anchorPane);
    }

}
