import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.File;
import java.io.IOException;

public class Main extends Application implements EventHandler<ActionEvent> {

    private TextField textField;
    private Button button;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("scena_poczatkowa.fxml"));
        primaryStage.setTitle("Cuboids Result");

        button = (Button) root.lookup("#button");
        textField = (TextField) root.lookup("#textField");

        button.setOnAction(this);
        textField.setOnAction(this);

        primaryStage.setResizable(false);
        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    @Override
    public void handle(ActionEvent event) {
        if (event.getSource() == button || event.getSource() == textField) {
            File tmpDir = new File(textField.getCharacters().toString());
            boolean exists = tmpDir.exists();
            if (!exists) {
                Alert alert = new Alert(Alert.AlertType.WARNING, "Such file does not exist!");
                alert.show();
            } else {
                ResultWindow resultWindow = new ResultWindow();
                Stage stage = new Stage();
                stage.setTitle(textField.getCharacters().toString());
                try {
                    resultWindow.start(stage);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
