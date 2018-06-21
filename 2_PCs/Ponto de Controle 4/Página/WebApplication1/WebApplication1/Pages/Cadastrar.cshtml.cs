using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace WebApplication1.Pages
{
    public class CadastrarModel : PageModel
    {

        public string Placa { get; set; }
        public string Cor { get; set; }



        public void OnGet()
        {

        }
    }
}