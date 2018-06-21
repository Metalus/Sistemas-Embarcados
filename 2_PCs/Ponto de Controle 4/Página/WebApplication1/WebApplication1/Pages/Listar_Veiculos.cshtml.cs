using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace WebApplication1.Pages
{
    public class Listar_VeiculosModel : PageModel
    {
        public Dictionary<string, string> Carros { get; set; }
        public void OnGet()
        {

            Carros = new Dictionary<string, string>();
            string[] placas = Directory.GetFiles("/home/pi/alpr/");
            for (int i = 0; i < placas.Length; i++)
            {
                using (FileStream fs = new FileStream(placas[i], FileMode.Open, FileAccess.Read))
                {
                    StreamReader reader = new StreamReader(fs);
                    Carros.Add(Path.GetFileName(placas[i]), reader.ReadLine());
                }
            }
        }
    }
}