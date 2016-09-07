package ca.riftekit.photofly;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.net.Uri;
import android.provider.MediaStore;
import android.provider.MediaStore.Images;
import android.provider.MediaStore.Images.Media;
import android.provider.MediaStore.MediaColumns;
import android.database.Cursor;
import android.content.ClipData;

import com.braintreepayments.api.BraintreeFragment;
import com.braintreepayments.api.exceptions.InvalidArgumentException;
import com.braintreepayments.api.PaymentRequest;

public class MyPayment
{
    private static String MY_TOKEN = "sandbox_fzvtkr2t_qz67z77n55cxt4g2";
    public String fragmentResult = "";

    public MyPayment(){

    }

    public BraintreeFragment createBraintreeFragment(Activity curActivity) {
	fragmentResult = "ok";
	BraintreeFragment fragment;
	try {
	    fragment = BraintreeFragment.newInstance(curActivity, MY_TOKEN);
	} catch (InvalidArgumentException e) {
	    fragment = new BraintreeFragment();
	    fragmentResult = "error";
	}
        return fragment;
    }

    public Intent paymentRequest(Context context) {
	PaymentRequest paymentRequest = new PaymentRequest()
	    .clientToken(MY_TOKEN);
      // startActivityForResult(paymentRequest.getIntent(this), REQUEST_CODE);
        // startActivity(paymentRequest.getIntent(context));
        return paymentRequest.getIntent(context);
    }

    public int getThree() {
	   return 3;
    }

    public String getMyId() {
	   return "123";
    }

}
