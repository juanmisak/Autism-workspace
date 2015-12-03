package com.j0n17.lightremote;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

public class Main extends Activity implements OnClickListener {

	Button Connect;
	ToggleButton OnOff;
	ToggleButton OnOff1;
	ToggleButton OnOff2;
	ToggleButton OnOff3;
	ToggleButton OnOff4;
	ToggleButton OnOff5;
	ToggleButton OnOff6;
	ToggleButton OnOff7;
	private String dataToSend;
	
	private static final String TAG = "Jon";
	private BluetoothAdapter mBluetoothAdapter = null;
	private BluetoothSocket btSocket = null;
	private OutputStream outStream = null;
	private static String address = "30:14:08:26:17:03";
	private static final UUID MY_UUID = UUID
			.fromString("00001101-0000-1000-8000-00805F9B34FB");
	private InputStream inStream = null;
    Handler handler = new Handler(); 
    byte delimiter = 10;
    boolean stopWorker = false;
    int readBufferPosition = 0;
    byte[] readBuffer = new byte[1024];

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		Connect = (Button) findViewById(R.id.connect);
		OnOff = (ToggleButton) findViewById(R.id.tgOnOff);
		OnOff1 = (ToggleButton) findViewById(R.id.tgOnOff1);
		OnOff2 = (ToggleButton) findViewById(R.id.tgOnOff2);
		OnOff3 = (ToggleButton) findViewById(R.id.tgOnOff3);
		OnOff4 = (ToggleButton) findViewById(R.id.tgOnOff4);
		OnOff5 = (ToggleButton) findViewById(R.id.tgOnOff5);
		OnOff6 = (ToggleButton) findViewById(R.id.tgOnOff6);
		OnOff7 = (ToggleButton) findViewById(R.id.tgOnOff7);

		Connect.setOnClickListener(this);
		OnOff.setOnClickListener(this);
		OnOff1.setOnClickListener(this);
		OnOff2.setOnClickListener(this);
		OnOff3.setOnClickListener(this);
		OnOff4.setOnClickListener(this);
		OnOff5.setOnClickListener(this);
		OnOff6.setOnClickListener(this);
		OnOff7.setOnClickListener(this);

		CheckBt();
		BluetoothDevice device = mBluetoothAdapter.getRemoteDevice(address);
		Log.e("Listo", device.toString());

	}

	@Override
	public void onClick(View control) {
		switch (control.getId()) {
		case R.id.connect:
				Connect();
			break;
		case R.id.tgOnOff:
			if (OnOff.isChecked()) {
				dataToSend = "G";
				writeData(dataToSend);
			} else if (!OnOff.isChecked()) {
				dataToSend = "g";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff1:
			if (OnOff1.isChecked()) {
				dataToSend = "F";
				writeData(dataToSend);
			} else if (!OnOff1.isChecked()) {
				dataToSend = "f";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff2:
			if (OnOff2.isChecked()) {
				dataToSend = "H";
				writeData(dataToSend);
			} else if (!OnOff2.isChecked()) {
				dataToSend = "h";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff3:
			if (OnOff3.isChecked()) {
				dataToSend = "B";
				writeData(dataToSend);
			} else if (!OnOff3.isChecked()) {
				dataToSend = "b";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff4:
			if (OnOff4.isChecked()) {
				dataToSend = "A";
				writeData(dataToSend);	
			} else if (!OnOff4.isChecked()) {
				dataToSend = "a";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff5:
			if (OnOff5.isChecked()) {
				dataToSend = "C";
				writeData(dataToSend);
			} else if (!OnOff5.isChecked()) {
				dataToSend = "c";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff6:
			if (OnOff6.isChecked()) {
				dataToSend = "D";
				writeData(dataToSend);
			} else if (!OnOff6.isChecked()) {
				dataToSend = "d";
				writeData(dataToSend);
			}
			break;
		case R.id.tgOnOff7:
			if (OnOff7.isChecked()) {
				dataToSend = "E";
				writeData(dataToSend);
			} else if (!OnOff7.isChecked()) {
				dataToSend = "e";
				writeData(dataToSend);
			}
			break;
		}
	}

	private void CheckBt() {
		mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

		if (!mBluetoothAdapter.isEnabled()) {
			Toast.makeText(getApplicationContext(), "Bluetooth Disabled !",
					Toast.LENGTH_SHORT).show();
		}

		if (mBluetoothAdapter == null) {
			Toast.makeText(getApplicationContext(),
					"Bluetooth null !", Toast.LENGTH_SHORT)
					.show();
		}
	}
	
		public void Connect() {
			Log.d(TAG, address);
			BluetoothDevice device = mBluetoothAdapter.getRemoteDevice(address);
			Log.d(TAG, "Connecting to ... " + device);
			mBluetoothAdapter.cancelDiscovery();
			try {
				btSocket = device.createRfcommSocketToServiceRecord(MY_UUID);
				btSocket.connect();
				Log.d(TAG, "Connection made.");
			} catch (IOException e) {
				try {
					btSocket.close();
				} catch (IOException e2) {
					Log.d(TAG, "Unable to end the connection");
				}
				Log.d(TAG, "Socket creation failed");
			}
			
			beginListenForData();
		}
	
	private void writeData(String data) {
		try {
			outStream = btSocket.getOutputStream();
		} catch (IOException e) {
			Log.d(TAG, "Bug BEFORE Sending stuff", e);
		}

		String message = data;
		byte[] msgBuffer = message.getBytes();

		try {
			outStream.write(msgBuffer);
		} catch (IOException e) {
			Log.d(TAG, "Bug while sending stuff", e);
		}
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
	
			try {
				btSocket.close();
			} catch (IOException e) {
			}
	}
	
	public void beginListenForData()   {
		 try {
				inStream = btSocket.getInputStream();
			} catch (IOException e) {
			}
		 
	        Thread workerThread = new Thread(new Runnable()
	        {
	            public void run()
	            {                
	               while(!Thread.currentThread().isInterrupted() && !stopWorker)
	               {
	                    try 
	                    {
	                        int bytesAvailable = inStream.available();                        
	                        if(bytesAvailable > 0)
	                        {
	                            byte[] packetBytes = new byte[bytesAvailable];
	                            inStream.read(packetBytes);
	                            for(int i=0;i<bytesAvailable;i++)
	                            {
	                                byte b = packetBytes[i];
	                                if(b == delimiter)
	                                {
	                                    byte[] encodedBytes = new byte[readBufferPosition];
	                                    System.arraycopy(readBuffer, 0, encodedBytes, 0, encodedBytes.length);
	                                    final String data = new String(encodedBytes, "US-ASCII");
	                                    readBufferPosition = 0;
	                                    handler.post(new Runnable()
	                                    {
	                                        public void run()
	                                        {
	                                        	/* 
	                                        	if(Result.getText().toString().equals("..")) {
	                                        		Result.setText(data);
	                                        	} else {
	                                        		Result.append("\n"+data);
	                                        	}
	                                        	
	                                        	You also can use Result.setText(data); it won't display multilines
	                                        	*/
	                                        	
	                                        }
	                                    });
	                                }
	                                else
	                                {
	                                    readBuffer[readBufferPosition++] = b;
	                                }
	                            }
	                        }
	                    } 
	                    catch (IOException ex) 
	                    {
	                        stopWorker = true;
	                    }
	               }
	            }
	        });

	        workerThread.start();
	    }
}
