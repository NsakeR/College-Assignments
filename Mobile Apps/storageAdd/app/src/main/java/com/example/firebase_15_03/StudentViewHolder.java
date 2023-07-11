package com.example.firebase_15_03;

import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class StudentViewHolder extends RecyclerView.ViewHolder {

    ImageView imageViewRV;
    TextView tvRVFirstNameLastName;
    TextView tvRVTinder;

    public StudentViewHolder(@NonNull View itemView) {
        super(itemView);

        imageViewRV = itemView.findViewById(R.id.imageViewRV);
        tvRVFirstNameLastName = itemView.findViewById(R.id.tvRVFirstNameLastName);
        tvRVTinder = itemView.findViewById(R.id.tvRVTinder);

    }
}
