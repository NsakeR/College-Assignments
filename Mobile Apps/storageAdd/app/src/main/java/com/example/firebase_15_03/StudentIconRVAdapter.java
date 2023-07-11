package com.example.firebase_15_03;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import androidx.annotation.NonNull;

import com.bumptech.glide.Glide;
import com.firebase.ui.firestore.FirestoreRecyclerAdapter;
import com.firebase.ui.firestore.FirestoreRecyclerOptions;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;

public class StudentIconRVAdapter extends FirestoreRecyclerAdapter<StudentIcon, StudentViewHolder> {

    /**
     * Create a new RecyclerView adapter that listens to a Firestore Query.  See {@link
     * FirestoreRecyclerOptions} for configuration options.
     *
     * @param options
     */
    FirebaseStorage storage;
    MainActivity2 mainActivity2;

    public StudentIconRVAdapter(@NonNull FirestoreRecyclerOptions<StudentIcon> options, MainActivity2 mainActivity2) {
        super(options);
        storage = FirebaseStorage.getInstance();
        this.mainActivity2 = mainActivity2;
    }

    public void loadImage(String path, ImageView imageView){
        StorageReference storageReference = storage.getReference().child(path);
        Glide.with(mainActivity2 /* context */)
                .load(storageReference)
                .into(imageView);
    }

    @Override
    protected void onBindViewHolder(@NonNull StudentViewHolder holder, int position, @NonNull StudentIcon model) {
        String lastName = model.getLastName();
        String firstName = model.getFirstName();
        String iconPath = model.getIcon();
        double tinder = model.getTinder();
        if (iconPath != "" && iconPath != null){
            holder.tvRVFirstNameLastName.setText(firstName+" "+lastName);
            holder.tvRVTinder.setText(String.valueOf(tinder));
            loadImage(iconPath, holder.imageViewRV);
        }
        else{
            holder.tvRVFirstNameLastName.setText(firstName+" "+lastName);
            holder.tvRVTinder.setText(String.valueOf(tinder));
            loadImage("/icons/low_res/default.png", holder.imageViewRV);
        }

    }

    @NonNull
    @Override
    public StudentViewHolder onCreateViewHolder(@NonNull ViewGroup group, int viewType) {
        View view = LayoutInflater.from(group.getContext())
                .inflate(R.layout.item_student_rv, group, false);

        return new StudentViewHolder(view);
    }
}//class
