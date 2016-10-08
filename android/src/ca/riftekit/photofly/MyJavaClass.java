package ca.riftekit.photofly;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.net.Uri;
import android.provider.MediaStore;
import android.provider.MediaStore.Images;
import android.provider.MediaStore.Images.Media;
import android.provider.MediaStore.MediaColumns;
import android.database.Cursor;
import android.content.ClipData;

public class MyJavaClass
{
    private static int RESULT_LOAD_IMAGE = 1;

    public MyJavaClass(){
    }

    public static Intent getOpenCameraIntent(){
	Intent intent = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
	return intent;
    }

    public static Intent getIntent(){
//	ACTION_GET_CONTENT
//	ACTION_PICK
    // Intent pickIntent = new Intent(Intent.ACTION_GET_CONTENT, android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        // Intent pickIntent = new Intent();
        // pickIntent.setAction(Intent.ACTION_PICK);
        Intent pickIntent = new Intent(Intent.ACTION_PICK, android.provider.MediaStore.Images.Media.INTERNAL_CONTENT_URI);
	pickIntent.setType("image/*");
	pickIntent.putExtra(Intent.EXTRA_ALLOW_MULTIPLE, true);
	pickIntent.putExtra(Intent.EXTRA_LOCAL_ONLY, true);	
	return pickIntent;
    }

    public static String[] handleResult(Intent imageReturnedIntent, Activity curActivity){

	ClipData clipData = imageReturnedIntent.getClipData();
	String[] ret;
	if (clipData == null){
	    ret = new String[1];
	    ret[0] = getStringPathFromImageUri(imageReturnedIntent.getData(), curActivity);
	    return ret;
	}

	ret = new String[ clipData.getItemCount()];
	for (int i = 0; i < clipData.getItemCount(); i++)
	{
	    Uri selectedImage = clipData.getItemAt(i).getUri();
//	    String[] filePathColumn = {MediaStore.Images.Media.DATA};

//	    Cursor cursor = curActivity.getContentResolver().query(
//		selectedImage, filePathColumn, null, null, null);
//	    cursor.moveToFirst();

//	    int columnIndex = cursor.getColumnIndex(filePathColumn[0]);
//	    String filePath = cursor.getString(columnIndex);
//	    cursor.close();
	    ret[i] = getStringPathFromImageUri(selectedImage, curActivity);
	}

	return ret;
    }

    public static String[] handleResult_v2(Intent imageReturnedIntent, Activity curActivity) {
    	String[] filePathColumn = { MediaStore.Images.Media.DATA };
    	String[] ret;

    	ClipData clipData = imageReturnedIntent.getClipData();
    	if (clipData != null) {
    		ret = new String[clipData.getItemCount() + 1];
    		for (int i = 0; i < clipData.getItemCount(); i++) {
    			Uri selectedImage = clipData.getItemAt(i).getUri();
    			ret[i] = getStringPathFromImageUri(selectedImage, curActivity);
    		}
    		ret[clipData.getItemCount()] = "First variant";
        	return ret;
    	}

    	Uri intentData = imageReturnedIntent.getData();
    	if (intentData != null) {
    		ret = new String[2];
    		ret[0] = getStringPathFromImageUri(intentData, curActivity);
    		ret[1] = "Second variant";
    		return ret;
    	}
    	
    	return new String[0];
    }

    private static String getStringPathFromImageUri(Uri imUri, Activity curActivity){
	String[] filePathColumn = {MediaStore.Images.Media.DATA};

	Cursor cursor = curActivity.getContentResolver().query(
	    imUri, filePathColumn, null, null, null);
	cursor.moveToFirst();

	int columnIndex = cursor.getColumnIndex(filePathColumn[0]);
	String filePath = cursor.getString(columnIndex);
	cursor.close();
	return filePath;
    }


}

