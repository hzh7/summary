package com.example.carapp.gson;

import com.google.gson.annotations.SerializedName;

/**
 * Created by HZH on 2017/2/23.
 */

public class Suggestion {

    @SerializedName("cw")
    public CarWash carWash;

    public class CarWash{
        @SerializedName("txt")
        public String info;
    }

}
