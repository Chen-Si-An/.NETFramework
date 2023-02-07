using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TPK_UserControl
{
    public partial class UserControl1 : Form
    {
        public UserControl1()
        {
            InitializeComponent();
            this.TopLevel = false;
            this.Visible = true;
        }

        public bool ChangeBtnToGreen()
        {
            btn.BackColor = Color.Green;
            return true;
        }

        public bool ChangeBtnToRed()
        {
            btn.BackColor = Color.Red;
            return true;
        }
    }
}
