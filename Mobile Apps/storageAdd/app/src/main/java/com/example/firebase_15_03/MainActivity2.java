package com.example.firebase_15_03;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import com.firebase.ui.firestore.FirestoreRecyclerOptions;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.Query;

public class MainActivity2 extends AppCompatActivity {

    RecyclerView rvStudenci;
    StudentIconRVAdapter adapter;
    //1.query
    //2.options
    //3.adapter
    //4.bind adapter and rv
    //5.manager layout on the rv
    //6.listening for the changes
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        rvStudenci = findViewById(R.id.rvShow);

        Query query = FirebaseFirestore.getInstance()
                .collection("student")
                .orderBy("tinder")
                .limit(50);

        /*FirestoreRecyclerOptions<Student> options = new FirestoreRecyclerOptions.Builder<Student>()
                .setQuery(query, Student.class)
                .build();
        adapter = new StudentRVAdapter(options);*/

        FirestoreRecyclerOptions<StudentIcon> options = new FirestoreRecyclerOptions.Builder<StudentIcon>()
                .setQuery(query, StudentIcon.class)
                .build();
        adapter = new StudentIconRVAdapter(options, this);

        rvStudenci.setLayoutManager(new LinearLayoutManager(getApplicationContext()));
        rvStudenci.setAdapter(adapter);

    }

    @Override
    protected void onStart() {
        super.onStart();
        adapter.startListening();
    }

    @Override
    protected void onStop() {
        super.onStop();
        adapter.stopListening();
    }
}