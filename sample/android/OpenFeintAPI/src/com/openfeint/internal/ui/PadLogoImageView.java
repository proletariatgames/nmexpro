package com.openfeint.internal.ui;

import android.content.Context;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

public class PadLogoImageView extends ImageView {
    private final String tag = "ImageView2";

    public PadLogoImageView(Context context) {
        super(context);

    }

    public PadLogoImageView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public PadLogoImageView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }
    
    @Override
    protected void onLayout(boolean changed, int left, int top, int right, int bottom) {
        super.onLayout(changed, left, top, right, bottom);
        Log.e(tag, String.valueOf(changed));
        Log.e(tag, String.valueOf(top));
        if (changed) {
            //TODO: should not a fixed number, work for xoom pad
            if (top < 350)
                this.setVisibility(View.INVISIBLE);
            else
                this.setVisibility(View.VISIBLE);
        }
    }
}
