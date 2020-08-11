using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace SocketTest {
	class Program {
		public static void StartClient() {
			byte[] bytes = new byte[1024];

			try {
				IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
				IPAddress ipAddress = ipHostInfo.AddressList[0];
				IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11000);

				Socket sender = new Socket(ipAddress.AddressFamily, SocketType.Stream,
					ProtocolType.Tcp);

				try {
					sender.Connect(remoteEP);

					Console.WriteLine("Socket connected to {0}", sender.RemoteEndPoint.ToString());
					byte[] msg = Encoding.ASCII.GetBytes("This is a test<EOF>");

					int bytesSent = sender.Send(msg);
					int bytesRec = sender.Receive(bytes);

				}
			}

		}

		static void Main(string[] args) {
			
		}
	}
}
