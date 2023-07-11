package com.example.firebase_15_03;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.firebase.geofire.GeoFireUtils;
import com.firebase.geofire.GeoLocation;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.android.material.textfield.TextInputEditText;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.SetOptions;
import com.google.type.LatLng;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    FirebaseFirestore db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        EditText firstName =  findViewById(R.id.input_firstName);
        EditText lastName =  findViewById(R.id.input_lastName);
        EditText tinder =  findViewById(R.id.input_tinder);
        EditText val =  findViewById(R.id.input_val);
        EditText docId =  findViewById(R.id.input_docId);
        EditText newKey =  findViewById(R.id.input_newKey);
        EditText lat =  findViewById(R.id.input_lat);
        EditText lng =  findViewById(R.id.input_lng);

        Button Save = findViewById(R.id.btn_save);
        Button Edit = findViewById(R.id.btn_edit);
        Button Show = findViewById(R.id.btn_show);
        Button Add = findViewById(R.id.btn_add);
        Button button_IconPath = findViewById(R.id.button_IconPath);
        Button Login = findViewById(R.id.btLogin);


        db = FirebaseFirestore.getInstance();

        button_IconPath.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), IconPathActivity.class);
                startActivity(intent);
            }
        });

        Save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Student st1 = new Student(String.valueOf(
                        firstName.getText()),
                        String.valueOf(lastName.getText()),
                        Double.valueOf(String.valueOf(tinder.getText())),
                        Integer.valueOf(String.valueOf(val.getText())));

                db.collection("student").document(String.valueOf(docId.getText())).set(st1);

            }
        });

        Add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Student st1 = new Student(String.valueOf(
                        firstName.getText()),
                        String.valueOf(lastName.getText()),
                        Double.valueOf(String.valueOf(tinder.getText())),
                        Integer.valueOf(String.valueOf(val.getText())));

                String docID = docId.getText().toString();
                String key = newKey.getText().toString();
                String latString = lat.getText().toString();
                String lngString = lng.getText().toString();

                double lat = new Double(latString);
                double lng = new Double(lngString);

                String hash = GeoFireUtils.getGeoHashForLocation(new GeoLocation(lat, lng));

                Map<String, Object> updates = new HashMap<>();
                updates.put("geohash", hash);
                updates.put("lat", lat);
                updates.put("lng", lng);

                DocumentReference londonRef = db.collection("student").document(docID);
                londonRef.update(updates)
                        .addOnCompleteListener(new OnCompleteListener<Void>() {
                            @Override
                            public void onComplete(@NonNull Task<Void> task) {
                                // ...
                            }
                        });



                Map<String, Object> data = new HashMap<>();

                data.put("capital2", true);

                db.collection("student").document("st11")
                        .set(data, SetOptions.merge());
            }
        });

        Login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), EmailPasswordActivity.class);
                startActivity(intent);
            }
        });


        Edit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                DocumentReference docRef = db.document("student/st11");//+docId.getText().toString().trim());

                docRef.get().addOnSuccessListener(new OnSuccessListener<DocumentSnapshot>() {
                    @Override
                    public void onSuccess(DocumentSnapshot documentSnapshot) {
                        Student student = documentSnapshot.toObject(Student.class);

                        if(student != null){
                            firstName.setText(student.getFirstName());
                            lastName.setText(student.getLastName());
                            tinder.setText(String.valueOf(student.getTinder()));
                            val.setText(String.valueOf(student.getVal()));
                        }
                    }
                });/*.addOnFailureListener(new OnFailureListener() {
                    @Override
                    public void onFailure(@NonNull Exception e) {

                    }
                });*/
            }
        });

        Show.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), MainActivity2.class);
                startActivity(intent);
            }
        });

    }
}