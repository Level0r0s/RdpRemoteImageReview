using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MSTSCLib;

namespace MstscApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            axMsRdpClient8NotSafeForScripting1.Server = textBox1.Text;
            axMsRdpClient8NotSafeForScripting1.UserName = textBox2.Text;
            axMsRdpClient8NotSafeForScripting1.AdvancedSettings9.ClearTextPassword = textBox3.Text;
            axMsRdpClient8NotSafeForScripting1.CreateVirtualChannels("DVCRRC");
            
            axMsRdpClient8NotSafeForScripting1.AdvancedSettings9.PluginDlls = "RemoteRenderServer.dll";


            axMsRdpClient8NotSafeForScripting1.Connect();
        }
    }
}
