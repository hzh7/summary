package com.example.carapp;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

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
        return inflater.inflate(R.layout.my_fragment,container,false);
    }
}
