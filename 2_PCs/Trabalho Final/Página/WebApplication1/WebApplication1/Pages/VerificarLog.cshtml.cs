using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace WebApplication1.Pages
{
    public class VerificarLogModel : PageModel
    {
        public void OnGet()
        {
            using (FileStream fs = new FileStream("/home/pi/alpr/log/alpr.log", FileMode.Open, FileAccess.Read))
            {
                StreamReader reader = new StreamReader(fs);
                TempData["log"] = reader.ReadToEnd().Replace("\n", "<br />");
            }
        }
    }
}