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
	Intent pickIntent = new Intent(Intent.ACTION_PICK, android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
	pickIntent.setType("image/*");
	pickIntent.putExtra(Intent.EXTRA_ALLOW_MULTIPLE, true);
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

