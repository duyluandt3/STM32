namespace USB_Custom_HID_Communication_GUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnconnection = new System.Windows.Forms.Button();
            this.txtmanufacturer = new System.Windows.Forms.TextBox();
            this.txtproductid = new System.Windows.Forms.TextBox();
            this.txtvendorid = new System.Windows.Forms.TextBox();
            this.txtproductname = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.zzzzzz = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtnumberpftranmit = new System.Windows.Forms.TextBox();
            this.btnsend = new System.Windows.Forms.Button();
            this.txtsend = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.txtnumberofreceive = new System.Windows.Forms.TextBox();
            this.txtreceive = new System.Windows.Forms.RichTextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnconnection);
            this.groupBox1.Controls.Add(this.txtmanufacturer);
            this.groupBox1.Controls.Add(this.txtproductid);
            this.groupBox1.Controls.Add(this.txtvendorid);
            this.groupBox1.Controls.Add(this.txtproductname);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.zzzzzz);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(22, 18);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox1.Size = new System.Drawing.Size(597, 354);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "USB Device Connection";
            // 
            // btnconnection
            // 
            this.btnconnection.Font = new System.Drawing.Font("Consolas", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnconnection.ForeColor = System.Drawing.Color.ForestGreen;
            this.btnconnection.Location = new System.Drawing.Point(236, 255);
            this.btnconnection.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnconnection.Name = "btnconnection";
            this.btnconnection.Size = new System.Drawing.Size(238, 74);
            this.btnconnection.TabIndex = 2;
            this.btnconnection.Text = "Connect";
            this.btnconnection.UseVisualStyleBackColor = true;
            this.btnconnection.Click += new System.EventHandler(this.btnconnection_Click);
            // 
            // txtmanufacturer
            // 
            this.txtmanufacturer.Location = new System.Drawing.Point(236, 191);
            this.txtmanufacturer.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtmanufacturer.Name = "txtmanufacturer";
            this.txtmanufacturer.ReadOnly = true;
            this.txtmanufacturer.Size = new System.Drawing.Size(344, 36);
            this.txtmanufacturer.TabIndex = 1;
            // 
            // txtproductid
            // 
            this.txtproductid.Location = new System.Drawing.Point(236, 142);
            this.txtproductid.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtproductid.Name = "txtproductid";
            this.txtproductid.ReadOnly = true;
            this.txtproductid.Size = new System.Drawing.Size(344, 36);
            this.txtproductid.TabIndex = 1;
            // 
            // txtvendorid
            // 
            this.txtvendorid.Location = new System.Drawing.Point(236, 92);
            this.txtvendorid.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtvendorid.Name = "txtvendorid";
            this.txtvendorid.ReadOnly = true;
            this.txtvendorid.Size = new System.Drawing.Size(344, 36);
            this.txtvendorid.TabIndex = 1;
            // 
            // txtproductname
            // 
            this.txtproductname.Location = new System.Drawing.Point(236, 43);
            this.txtproductname.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtproductname.Name = "txtproductname";
            this.txtproductname.ReadOnly = true;
            this.txtproductname.Size = new System.Drawing.Size(344, 36);
            this.txtproductname.TabIndex = 1;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(9, 191);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(168, 28);
            this.label4.TabIndex = 0;
            this.label4.Text = "Manufacturer";
            // 
            // zzzzzz
            // 
            this.zzzzzz.AutoSize = true;
            this.zzzzzz.Location = new System.Drawing.Point(9, 146);
            this.zzzzzz.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.zzzzzz.Name = "zzzzzz";
            this.zzzzzz.Size = new System.Drawing.Size(142, 28);
            this.zzzzzz.TabIndex = 0;
            this.zzzzzz.Text = "Product ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 97);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(129, 28);
            this.label2.TabIndex = 0;
            this.label2.Text = "Vendor ID";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 48);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(168, 28);
            this.label1.TabIndex = 0;
            this.label1.Text = "Product Name";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtnumberpftranmit);
            this.groupBox2.Controls.Add(this.btnsend);
            this.groupBox2.Controls.Add(this.txtsend);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(22, 382);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox2.Size = new System.Drawing.Size(597, 312);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Transmit";
            // 
            // txtnumberpftranmit
            // 
            this.txtnumberpftranmit.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtnumberpftranmit.Location = new System.Drawing.Point(9, 251);
            this.txtnumberpftranmit.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtnumberpftranmit.Name = "txtnumberpftranmit";
            this.txtnumberpftranmit.ReadOnly = true;
            this.txtnumberpftranmit.Size = new System.Drawing.Size(364, 36);
            this.txtnumberpftranmit.TabIndex = 1;
            // 
            // btnsend
            // 
            this.btnsend.Enabled = false;
            this.btnsend.Font = new System.Drawing.Font("Consolas", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnsend.ForeColor = System.Drawing.Color.ForestGreen;
            this.btnsend.Location = new System.Drawing.Point(393, 217);
            this.btnsend.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnsend.Name = "btnsend";
            this.btnsend.Size = new System.Drawing.Size(183, 74);
            this.btnsend.TabIndex = 2;
            this.btnsend.Text = "Send";
            this.btnsend.UseVisualStyleBackColor = true;
            this.btnsend.Click += new System.EventHandler(this.btnsend_Click);
            // 
            // txtsend
            // 
            this.txtsend.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtsend.Location = new System.Drawing.Point(9, 38);
            this.txtsend.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtsend.Name = "txtsend";
            this.txtsend.Size = new System.Drawing.Size(565, 167);
            this.txtsend.TabIndex = 0;
            this.txtsend.Text = "";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(9, 217);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(363, 28);
            this.label3.TabIndex = 0;
            this.label3.Text = "Number of Transmited (Byte)";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.txtnumberofreceive);
            this.groupBox4.Controls.Add(this.txtreceive);
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox4.Location = new System.Drawing.Point(22, 703);
            this.groupBox4.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox4.Size = new System.Drawing.Size(597, 529);
            this.groupBox4.TabIndex = 1;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Receive";
            // 
            // txtnumberofreceive
            // 
            this.txtnumberofreceive.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtnumberofreceive.Location = new System.Drawing.Point(393, 477);
            this.txtnumberofreceive.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtnumberofreceive.Name = "txtnumberofreceive";
            this.txtnumberofreceive.ReadOnly = true;
            this.txtnumberofreceive.Size = new System.Drawing.Size(181, 36);
            this.txtnumberofreceive.TabIndex = 1;
            // 
            // txtreceive
            // 
            this.txtreceive.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtreceive.Location = new System.Drawing.Point(9, 38);
            this.txtreceive.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtreceive.Name = "txtreceive";
            this.txtreceive.ReadOnly = true;
            this.txtreceive.Size = new System.Drawing.Size(565, 427);
            this.txtreceive.TabIndex = 0;
            this.txtreceive.Text = "";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(9, 482);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(337, 28);
            this.label5.TabIndex = 0;
            this.label5.Text = "Number of Received (Byte)";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(638, 1050);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "USB Custom HID Communication GUI";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtproductid;
        private System.Windows.Forms.TextBox txtvendorid;
        private System.Windows.Forms.TextBox txtproductname;
        private System.Windows.Forms.Label zzzzzz;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnconnection;
        private System.Windows.Forms.TextBox txtmanufacturer;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txtnumberpftranmit;
        private System.Windows.Forms.Button btnsend;
        private System.Windows.Forms.RichTextBox txtsend;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox txtnumberofreceive;
        private System.Windows.Forms.RichTextBox txtreceive;
        private System.Windows.Forms.Label label5;
    }
}

