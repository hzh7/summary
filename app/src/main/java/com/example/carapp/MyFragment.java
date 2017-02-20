package com.example.carapp;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import static android.text.style.TtsSpan.ARG_TEXT;

/**
 * Created by HZH on 2017/2/20.
 */

public class MyFragment extends android.support.v4.app.Fragment{
    public MyFragment() {}

    public static MyFragment newInstance(String text) {
        Bundle args = new Bundle();
        args.putString(ARG_TEXT, text);

        MyFragment sampleFragment = new MyFragment();
        sampleFragment.setArguments(args);

        return sampleFragment;
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.my_fragment,container,false);
        Button button = (Button) view.findViewById(R.id.button1);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getActivity(), "you clicked this", Toast.LENGTH_SHORT).show();
            }
        });
        return view;
    }
}
