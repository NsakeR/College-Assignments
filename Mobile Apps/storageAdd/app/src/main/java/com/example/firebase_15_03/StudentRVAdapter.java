package com.example.firebase_15_03;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;

import com.firebase.ui.firestore.FirestoreRecyclerAdapter;
import com.firebase.ui.firestore.FirestoreRecyclerOptions;

public class StudentRVAdapter extends FirestoreRecyclerAdapter<Student, StudentViewHolder> {
    /**
     * Create a new RecyclerView adapter that listens to a Firestore Query.  See {@link
     * FirestoreRecyclerOptions} for configuration options.
     *
     * @param options
     */
    public StudentRVAdapter(@NonNull FirestoreRecyclerOptions<Student> options) {
        super(options);
    }

    @Override
    protected void onBindViewHolder(@NonNull StudentViewHolder holder, int position, @NonNull Student model) {
        String lastName = model.getLastName();
        String firstName = model.getFirstName();
        double tinder = model.getTinder();

        holder.tvRVFirstNameLastName.setText(firstName+" "+lastName);
        holder.tvRVTinder.setText(String.valueOf(tinder));
    }//onBindVH

    @NonNull
    @Override
    public StudentViewHolder onCreateViewHolder(@NonNull ViewGroup group, int viewType) {
        View view = LayoutInflater.from(group.getContext())
                .inflate(R.layout.item_student_rv, group, false);

        return new StudentViewHolder(view);
    }//onCreateVH
}
