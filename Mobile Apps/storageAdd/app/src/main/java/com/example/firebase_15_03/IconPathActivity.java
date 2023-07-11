package com.example.firebase_15_03;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import com.bumptech.glide.Glide;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;

public class IconPathActivity extends AppCompatActivity {
    EditText input_pathIcon;
    Button btn_loadImage;
    ImageView imageView_loadIcon;
    FirebaseStorage storage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_icon_path);

        storage = FirebaseStorage.getInstance();
        input_pathIcon = findViewById(R.id.input_pathIcon);
        btn_loadImage = findViewById(R.id.btn_loadIcon);
        imageView_loadIcon = findViewById(R.id.imageView_loadIcon);

        btn_loadImage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String path = input_pathIcon.getText().toString().trim();
                loadImage(path);
            }
        });
    }

    public void loadImage(String path){
        StorageReference storageReference = storage.getReference().child(path);
        Glide.with(this /* context */)
                .load(storageReference)
                .into(imageView_loadIcon);
    }
}