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

public class CircleFragment extends android.support.v4.app.Fragment{
    public CircleFragment() {}

    public static CircleFragment newInstance(String text) {
        Bundle args = new Bundle();
        args.putString(ARG_TEXT, text);

        CircleFragment sampleFragment = new CircleFragment();
        sampleFragment.setArguments(args);

        return sampleFragment;
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.circle_fragment,container,false);
    }
}
